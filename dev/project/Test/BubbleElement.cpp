#include "BubbleElement.h"
#include "VisibleRect.h"
#include "MatrixField.h"

int BubbleElement::m_BubbleSize = 40;
BubbleElement::BubbleMap_t BubbleElement::m_BubblesMap;

BubbleElement::BubbleElement(int type)
	: m_Type(type)
{
	if (m_BubblesMap.find(type) != m_BubblesMap.end())
	{
		SetType(type);
	}
}

BubbleElement::~BubbleElement()
{

}

void BubbleElement::SetType(int type)
{
	if (m_BubblesMap.find(type) != m_BubblesMap.end())
	{
		char strType[64];
		sprintf(strType, "data/sphere0%d.png", type + 1);
		this->initWithFile(strType);

		CCRect rect = m_BubblesMap[type][0];		
		//this->setTextureRect(rect);
		this->setAnchorPoint(CCPointMake(0.0f, 0.0f));

		m_Type = type;
	}
	else
	{
		int j = 0;
	}
}

void BubbleElement::FakeBubblesInit()
{
	for(int j = 0; j < MatrixField::GetMaxTypes() + 1; ++j)
	{
		std::vector<CCRect> animFrames;
		animFrames.push_back(CCRectMake(0, j * 45, m_BubbleSize, m_BubbleSize));

		m_BubblesMap[j] = animFrames;
	}
}