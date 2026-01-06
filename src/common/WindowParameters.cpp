/*
 * Copyright 2025 Forge-of-Ovorldule and Mr_Soul-Forest(https://github.com/Mr-Soul-Forest)
 * https://github.com/Forge-of-Ovorldule
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#include "../../include/OvorlduleGraphics/WindowParameters.h"

namespace Ovorldule
{
WindowParameters::WindowParameters ()
    : m_size (800, 600), m_title ("New window")
{
}

WindowParameters& WindowParameters::size (const Vector2i& size)
{
	m_size = size;
	return *this;
}

WindowParameters& WindowParameters::size (int width, int height)
{
	m_size = Vector2i (width, height);
	return *this;
}

WindowParameters& WindowParameters::title (const std::string& title)
{
	m_title = title;
	return *this;
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