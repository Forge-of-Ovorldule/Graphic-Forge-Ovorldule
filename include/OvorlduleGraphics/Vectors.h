/*
 * Copyright 2025 Forge-of-Ovorldule
 * https://github.com/Forge-of-Ovorldule
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#pragma once

namespace Ovorldule
{
class Vector2i
{
	public:
		int x; // width
		int y; // height

		Vector2i (int x = 0, int y = 0);
		~Vector2i ();

		// Геттеры для width/height
		int width () const
		{
			return x;
		}
		int height () const
		{
			return y;
		}
};
} // namespace Ovorldule