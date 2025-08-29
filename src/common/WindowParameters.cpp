/*
 * Copyright 2025 Forge-of-Ovorldule
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