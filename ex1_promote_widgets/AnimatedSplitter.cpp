#include "AnimatedSplitter.h"
#include <QtCore/QPropertyAnimation>


AnimatedSplitter::AnimatedSplitter(QWidget* parent, int animationDuration, const QEasingCurve& curve)
    : QSplitter(parent)
    , m_animation(new QPropertyAnimation(this, "splitterHandlePosition"))
    , m_splitterHandlePosition(0)
{
    connect(m_animation, &QPropertyAnimation::finished, this, &AnimatedSplitter::animationFinished);

    m_animation->setDuration(animationDuration);
    m_animation->setEasingCurve(curve);
}

void AnimatedSplitter::moveHandleAt(int position)
{
    m_animation->stop();

    m_animation->setStartValue(QSplitter::sizes()[0]);
    m_animation->setEndValue(position);

    m_animation->start();
}

void AnimatedSplitter::setAnimationDuration(int msec)
{
    m_animation->setDuration(msec);
}

int AnimatedSplitter::animationDuration()
{
    return m_animation->duration();
}

void AnimatedSplitter::setHandleAt(int position)
{
    m_splitterHandlePosition = position;
    moveSplitter(m_splitterHandlePosition, 1);
}

int AnimatedSplitter::handlePosition() const
{
    return m_splitterHandlePosition;
}
