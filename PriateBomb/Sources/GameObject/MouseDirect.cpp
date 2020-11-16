#include "MouseDirect.h"
#include <math.h>

void MouseDirect::Update(float deltaTime, sf::Vector2i pointMouse)
{

    float width = abs(pointMouse.x - m_PointA.x);
    float height = abs(pointMouse.y - m_PointA.y);
    float TanAngle = width / height;
    TanAngle = atan(TanAngle);
    m_Angle = 180.f / b2_pi*TanAngle;
    m_VectorUnit.x = abs(sin(TanAngle));
    m_VectorUnit.y = abs(cos(TanAngle));

    if (pointMouse.x < m_PointA.x)
    {
        m_Angle =-m_Angle;
        m_VectorUnit.x = -m_VectorUnit.x;
    }
    if (pointMouse.y > m_PointA.y)
    {
        if (pointMouse.x > m_PointA.x)
        {
            float delta = 90.f + 90.f - m_Angle;
            m_Angle = delta;
        }
        else
        {
            float delta = -180.f - m_Angle;
            m_Angle = delta;
        }
    }
    else m_VectorUnit.y = -m_VectorUnit.y;
   
   //printf("%f %f\n", m_VectorUnit.x, m_VectorUnit.y);
}
b2Vec2 MouseDirect::getVectorUnit()
{
    return m_VectorUnit;
}

float MouseDirect::getAngle()
{
    return m_Angle;
}

void MouseDirect::setPointA(sf::Vector2f a)
{
    m_PointA = a;
}

