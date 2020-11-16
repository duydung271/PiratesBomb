#include "IPlayer.h"
#include "MouseDirect.h"
#include "Rocket.h"
#include "HearBar.h"
#include "AttributeItem.h"


class Player :
	public IPlayer
{
public:
	enum WEAPON
	{
		WEAPON_BOMB=0,
		WEAPON_ROCKET,
	};
	Player();
	~Player();
	void SetAction();
	void SetState(IPState* newState);

	void Init();
	void Draw(sf::RenderWindow* window);
	void Update(float deltaTime);

	IPState* GetState();

	void SetNextAction(IPState::STATE nextAction);
	inline AnimationComponent* GetAnimation()
	{
		return m_Animation;
	}
	inline AttributeComponent* GetAttribute()
	{
		return m_Attribute;
	}
	inline b2Body* GetBody()
	{
		return m_HitBox->Body;
	}
	void WeaponUpdate(float deltaTime);
	void CollisionDamge(float deltaTime);
	

	
protected:
	void ApplyAttributeDate();
	float m_CountTimeTakeDam;// thoi gian giua 2 lan nhan Dame
	IPState::STATE m_CurrentAction;
	IPState::STATE m_NextAction;
	WEAPON m_CurrentWeapon;

	AnimationComponent* m_Animation;
	HitCircleComponent* m_HitBox;
	AttributeComponent* m_Attribute;
	BombManager* m_BombManager;
	Rocket* m_Rocket;
	HeartBar* m_HeartBar;
private:
	IPState* m_CurrentState;
	IPState* m_JumpState;
	IPState* m_RunState;
	IPState* m_IdleState;
	IPState* m_FallState;
	IPState* m_JumpAnticipationState;
	IPState* m_GroundState;
	IPState* m_HitState;
	IPState* m_DeadHitState;
	IPState* m_DeadGroundState;
};