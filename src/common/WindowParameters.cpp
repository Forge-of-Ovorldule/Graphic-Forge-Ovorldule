#include "../../include/OvorlduleGraphics/WindowParameters.h"

namespace Ovorldule
{
WindowParameters::WindowParameters ()
    : m_size (800, 600), m_title ("New window")
{
}

WindowParameters::WindowParameters (const Vector2i& size, const std::string& title)
    : m_size (size), m_title (title)
{
}

const Vector2i& WindowParameters::getSize () const
{
	return m_size;
}

const std::string& WindowParameters::getTitle () const
{
	return m_title;
}
} // namespace Ovorldule