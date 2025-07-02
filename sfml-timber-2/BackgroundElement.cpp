#include "stdafx.h"
#include "BackgroundElement.h"
#include "Player.h"

BackgroundElement::BackgroundElement(const std::string& texPlayerId, const std::string& name)
	: SpriteGo(texPlayerId, name)
{
}

void BackgroundElement::SetStartPos(sf::Vector2f v)
{
	startPos = v;
	SetPosition(v);
}

void BackgroundElement::SetSide(Sides side)
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	float scale = Utils::RandomRange(minScale, maxScale);
	float y = Utils::RandomRange(minY, maxY);

	switch (side)
	{
	case Sides::Left:
		direction = { 1.f, 0.f };
		SetScale({ -scale, scale });
		if(moveType == MoveType::Crazy) SetPosition({ 0.f, y });
		else SetPosition({ -150.f, y });
		break;
	case Sides::Right:
		direction = { -1.f, 0.f };
		SetScale({ scale, scale });
		if (moveType == MoveType::Crazy) SetPosition({ bounds.width, y });
		else SetPosition({ bounds.width + 150.f, y });
		break;
	}
	speed = Utils::RandomRange(minSpeed, maxSpeed);

	if (moveType == MoveType::Wave)
	{
		startPos = GetPosition();
		amplitude = Utils::RandomRange(50.f, 150.f);
		frequency = Utils::RandomRange(1.f, 5.f);
		timer = 0.f;
	}
}

void BackgroundElement::SetMoveType(MoveType type)
{
	moveType = type;
}


void BackgroundElement::Reset()
{
	SpriteGo::Reset();

	SetOrigin(Origins::MC);
	SetSide((Sides)Utils::RandomRange(0, 2));
	float x = Utils::RandomRange(0.f, FRAMEWORK.GetWindowBounds().width);
	SetPosition({ x, GetPosition().y });
}

void BackgroundElement::Update(float dt)
{
	sf::Vector2f pos = GetPosition();

	switch (moveType)
	{
	case MoveType::Linear:
		pos += direction * speed * dt;
		break;

	case MoveType::Wave:
		timer += dt;
		pos.x += direction.x * speed * dt;
		pos.y = startPos.y + amplitude * sin(timer * frequency);
		break;

	case MoveType::Fly:
		if (isFlying)
		{
			sf::Vector2f gravity(0.f, 4000.f);
			vel += gravity * dt;
			pos += vel * dt;
		}
		break;
	case MoveType::Crazy:
		pos.x += direction.x * (float)(rand() % 400 + 300) * dt;
		pos.y += direction.y * (float)(rand() % 400 + 300) * dt;
		if (rand() % 100 < 1) {
			direction.x = ((rand() % 2001) - 1000) / 1000.f;
			direction.y = ((rand() % 2001) - 1000) / 1000.f;
		}
		break;
	}

	SetPosition(pos);

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	if (moveType != MoveType::Fly && (pos.x < -200.f || pos.x > bounds.width + 200.f))
	{
		SetSide((Sides)Utils::RandomRange(0, 2));
	}

	if (moveType == MoveType::Fly && (
		pos.x < -400.f || pos.x > bounds.width + 400.f || pos.y > bounds.height + 200.f))
	{
		isFlying = false;
		SetActive(false);  
	}
}
