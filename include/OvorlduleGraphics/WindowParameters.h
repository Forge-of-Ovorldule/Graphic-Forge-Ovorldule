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
		WindowParameters (const Vector2i& size, const std::string& title);

		const Vector2i& getSize () const;
		const std::string& getTitle () const;
};
} // namespace Ovorldule