/*
 * Copyright 2025 Forge-of-Ovorldule and Mr_Soul-Forest(https://github.com/Mr-Soul-Forest)
 * https://github.com/Forge-of-Ovorldule
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#pragma once
#include <string>
#include "Vectors.h"

namespace Ovorldule
{
class WindowParameters
{
	private:
		Vector2i m_size;
		std::string m_title;

	public:
		WindowParameters ();

		WindowParameters& size (const Vector2i& size);
		WindowParameters& size (int width, int height);
		WindowParameters& title (const std::string& title);

		const Vector2i& getSize () const;
		const std::string& getTitle () const;
};
} // namespace Ovorldule