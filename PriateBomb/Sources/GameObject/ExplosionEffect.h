#pragma once
#include "../GameManager/ResourceManager.h"
#include "AttributeComponent.h"

class MyQueryCallback : public b2QueryCallback {
public:
    std::vector<b2Body*> foundBodies;

    bool ReportFixture(b2Fixture* fixture) {
        foundBodies.push_back(fixture->GetBody());
        return true;//keep going to find all fixtures in the query area
    }
};

class ExplosionEffect
{
public:
    ExplosionEffect(b2Body* newbody)
    {
        m_blastRadius = 3;
        m_blastPower = 1000;
        m_grenadeBody = newbody;
    }

    void setBody(b2Body* newbody)
    {
        m_grenadeBody = newbody;
    }
    //this is the same for proximity and raycast methods so we can put it in a common function
    void applyBlastImpulse(b2Body* body, b2Vec2 blastCenter, b2Vec2 applyPoint, float blastPower)
    {
        //ignore the grenade itself, and any non-dynamic bodies
        if (body == m_grenadeBody || body->GetType() != b2_dynamicBody)
            return;
        if (body->GetFixtureList()->GetFilterData().categoryBits & CATEGORY_BULLET) return;
        if (body->GetFixtureList()->GetFilterData().categoryBits & CATEGORY_PLAYER
            && m_grenadeBody->GetFixtureList()->GetFilterData().categoryBits & CATEGORY_BULLET) return;
        b2Vec2 blastDir = applyPoint - blastCenter;
        float distance = blastDir.Normalize();
        //ignore bodies exactly at the blast point - blast direction is undefined
        if (distance == 0)
            return;
        float invDistance = 1 / distance;
        float impulseMag = blastPower * invDistance * invDistance;
        impulseMag = b2Min(impulseMag, 500.0f);
        body->ApplyLinearImpulse(impulseMag * blastDir, applyPoint,true);

        //Data processer
        AttributeComponent* thisEx = (AttributeComponent*)m_grenadeBody->GetUserData();//Moi vu no se co damge rieng duoc set o trong Attribute(cua vat the)
        if (body->GetFixtureList()->GetFilterData().categoryBits & CATEGORY_PLAYER
            && m_grenadeBody->GetFixtureList()->GetFilterData().categoryBits&CATEGORY_BOMB)
        {
            AttributeComponent* tmp = (AttributeComponent*)body->GetUserData();
            tmp->LoseHP(10.f);
        }else
        if (body->GetFixtureList()->GetFilterData().categoryBits & CATEGORY_MONSTER)
        {
            AttributeComponent* tmp = (AttributeComponent*)body->GetUserData();

            tmp->LoseHP(thisEx->getDamge());
        }else
        if ((body->GetFixtureList()->GetFilterData().categoryBits & CATEGORY_BOMB)
                &&(m_grenadeBody->GetFixtureList()->GetFilterData().categoryBits&CATEGORY_BULLET))
        {
            AttributeComponent* tmp = (AttributeComponent*)body->GetUserData();
            tmp->setHP(0);
        } else if (body->GetFixtureList()->GetFilterData().categoryBits & CATEGORY_BOSS)
        {
            AttributeComponent* tmp = (AttributeComponent*)body->GetUserData();

            tmp->LoseHP(thisEx->getDamge());
        }
        else if (body->GetFixtureList()->GetFilterData().categoryBits & CATEGORY_BULLET_BOSS)
        {
            AttributeComponent* tmp = (AttributeComponent*)body->GetUserData();
            tmp->LoseHP(thisEx->getDamge());
        }
        
    }

    void explode_proximity()
    {
        b2Vec2 center = m_grenadeBody->GetPosition();

        //find all fixtures within blast radius AABB
        MyQueryCallback queryCallback;
        b2AABB aabb;
        aabb.lowerBound = center - b2Vec2(m_blastRadius, m_blastRadius);
        aabb.upperBound = center + b2Vec2(m_blastRadius, m_blastRadius);
        World::GetInstance()->GetWorld()->QueryAABB(&queryCallback, aabb);

        //check which of these have their center of mass within the blast radius
        for (int i = 0; i < queryCallback.foundBodies.size(); i++) {
            b2Body* body = queryCallback.foundBodies[i];
            b2Vec2 bodyCom = body->GetWorldCenter();
            //ignore bodies outside the blast range
            if ((bodyCom - center).Length() >= m_blastRadius)
                continue;
            applyBlastImpulse(body, center, bodyCom, m_blastPower * 0.05f);//scale blast power to roughly match results of other methods at 32 rays
        }
       // printf("%d\n", queryCallback.foundBodies.size());
    }
    void setBlastRadius(float blastRadius);
    void setBlastPower(float blastPower);
private:

    float m_blastRadius;;
    float m_blastPower ;
    b2Body* m_grenadeBody;
};