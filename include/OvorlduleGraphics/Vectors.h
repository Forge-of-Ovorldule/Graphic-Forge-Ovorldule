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