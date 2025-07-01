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
		SetPosition({ -150.f, y });
		break;
	case Sides::Right:
		direction = { -1.f, 0.f };
		SetScale({ scale, scale });
		SetPosition({ bounds.width + 150.f, y });
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
	case BackgroundElement::MoveType::Linear:
		pos += direction * speed * dt;
		break;
	case BackgroundElement::MoveType::Wave:
		timer += dt;
		pos.x += direction.x * speed * dt;
		pos.y = startPos.y + amplitude * sin(timer * frequency);
		break;
	case BackgroundElement::MoveType::Fly:
		sf::Vector2f dir((rand() % 2 == 0) ? -1.f : 1.f, -1.f);
		LogsVel.push_back(dir * logSpeed);
		FlyingLogs.push_back(true);
		break;
	}

	SetPosition(pos);

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	if (pos.x < -200.f || pos.x > bounds.width + 200.f)
	{
		SetSide((Sides)Utils::RandomRange(0, 2));
	}
}
