#include "stdafx.h"
#include "Utils.h"

std::random_device Utils::rd;
std::mt19937 Utils::gen;

void Utils::Init()
{
    gen.seed(rd());
}

float Utils::getDistanceWithSize(const sf::Sprite& a, const sf::Sprite& b)
{
    sf::FloatRect boundsA = a.getGlobalBounds();
    sf::FloatRect boundsB = b.getGlobalBounds();

    //�߾Ӱ� ����
    sf::Vector2f centerA(boundsA.left + boundsA.width / 2.f, boundsA.top + boundsA.height / 2.f);
    sf::Vector2f centerB(boundsB.left + boundsB.width / 2.f, boundsB.top + boundsB.height / 2.f);

    //��Ÿ��� ���� �̿��ؼ� ũ�� ����
    float dx = centerA.x - centerB.x;
    float dy = centerA.y - centerB.y;
    float centerDistance = sqrt(dx * dx + dy * dy); // �߾ӿ������� �Ÿ�

    //�ܰ��� �̿��ؼ� ��ǥ�� ���
    float overlapX = (boundsA.width + boundsB.width) / 2.f;
    float overlapY = (boundsA.height + boundsB.height) / 2.f;
    float edgeDistanceX = std::max(0.f, std::abs(dx) - overlapX);
    float edgeDistanceY = std::max(0.f, std::abs(dy) - overlapY);

    // �����ڸ� �Ÿ��� ���� �Ÿ� 
    return sqrt(edgeDistanceX * edgeDistanceX + edgeDistanceY * edgeDistanceY);
}

float Utils::RandomValue()
{
    std::uniform_real_distribution<float> dist(0.f, 1.f);
    return dist(gen);
}

int Utils::RandomRange(int min, int maxExclude)
{
    std::uniform_int_distribution<int> dist(min, maxExclude - 1);
	return dist(gen);
}

float Utils::RandomRange(float min, float max)
{
    std::uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}

sf::Vector2f Utils::SetOrigin(sf::Transformable& obj, Origins preset, const sf::FloatRect rect)
{
    sf::Vector2f newOrigin(rect.width, rect.height);
    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    obj.setOrigin(newOrigin);
    return newOrigin;
}

sf::Vector2f Utils::SetOrigin(sf::Shape& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utils::SetOrigin(sf::Text& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utils::SetOrigin(sf::Sprite& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}