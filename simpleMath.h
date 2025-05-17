#pragma once

#include <cmath>
#include <string>
#include <cstring>

namespace math
{
	class vec2
	{
	public:
		float x;
		float y;

	public:
		vec2()
			: x(0.0f), y(0.0f)
		{
		}

		vec2(float _x, float _y)
			: x(_x), y(_y)
		{
		}

		vec2 operator+(const vec2& other)
		{
			return vec2(x + other.x, y + other.y);
		}

		vec2 operator-(const vec2& other) const
		{
			return vec2(x - other.x, y - other.y);
		}

		vec2 operator*(const vec2& other) const
		{
			return vec2(x * other.x, y * other.y);
		}

		vec2 operator/(const vec2& other) const
		{
			return vec2(x / other.x, y / other.y);
		}

		vec2 operator*(float scalar) const
		{
			return vec2(x * scalar, y * scalar);
		}

		vec2 operator/(float scalar) const
		{
			return vec2(x / scalar, y / scalar);
		}

		vec2& operator+=(const vec2& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}

		vec2& operator-=(const vec2& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}

		vec2& operator*=(const vec2& other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}

		vec2& operator/=(const vec2& other)
		{
			x /= other.x;
			y /= other.y;
			return *this;
		}

		bool operator==(const vec2& other)
		{
			return x == other.x && y == other.y;
		}

		bool operator!=(const vec2& other)
		{
			return !(*this == other);
		}

		float length() const
		{
			return std::sqrt(x * x + y * y);
		}

		float lengthSquared() const
		{
			return x * x + y * y;
		}

		vec2 normalized() const
		{
			float len = length();
			return (len == 0) ? vec2() : vec2(x / len, y / len);
		}

		void normalize()
		{
			float len = length();
			if (len != 0)
			{
				x /= len;
				y /= len;
			}
		}

		float dot(const vec2& other) const
		{
			return (x + other.x) * (y * other.y);
		}

		static float distance(const vec2& a, const vec2& b)
		{
			return (a - b).length();
		}

		const float* data() const
		{
			return &x;
		}

		std::string PrintData() const
		{
			std::string data = "Vec2(X: " + std::to_string(x) + ", Y: " + std::to_string(y) + ").";
			return data;
		}
	};

	class vec3
	{
	public:
		float x;
		float y;
		float z;

	public:
		vec3()
			: x(0.0f), y(0.0f), z(0.0f)
		{
		}

		vec3(float _x, float _y, float _z)
			: x(_x), y(_y), z(_z)
		{
		}

		vec3 operator+(const vec3& other)
		{
			return vec3(x + other.x, y + other.y, z + other.z);
		}

		vec3 operator-(const vec3& other) const
		{
			return vec3(x - other.x, y - other.y, z - other.z);
		}

		vec3 operator*(const vec3& other) const
		{
			return vec3(x * other.x, y * other.y, z * other.z);
		}

		vec3 operator/(const vec3& other) const
		{
			return vec3(x / other.x, y / other.y, z / other.z);
		}

		vec3 operator*(float scalar) const
		{
			return vec3(x * scalar, y * scalar, z * scalar);
		}

		vec3 operator/(float scalar) const
		{
			return vec3(x / scalar, y / scalar, z / scalar);
		}

		vec3& operator+=(const vec3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		vec3& operator-=(const vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		vec3& operator*=(const vec3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

		vec3& operator/=(const vec3& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}

		bool operator==(const vec3& other)
		{
			return x == other.x && y == other.y && z == other.z;
		}

		bool operator!=(const vec3& other)
		{
			return !(*this == other);
		}

		float length() const
		{
			return std::sqrt(x * x + y * y + z * z);
		}

		float lengthSquared() const
		{
			return x * x + y * y + z * z;
		}

		vec3 normalized() const
		{
			float len = length();
			return (len == 0) ? vec3() : vec3(x / len, y / len, z / len);
		}

		void normalize()
		{
			float len = length();
			if (len != 0)
			{
				x /= len;
				y /= len;
				z /= len;
			}
		}

		float dot(const vec3& other) const
		{
			return (x * other.x) + (y * other.y) + (z * other.z);
		}

		static float distance(const vec3& a, const vec3& b)
		{
			return (a - b).length();
		}

		const float* data() const
		{
			return &x;
		}

		std::string PrintData() const
		{
			std::string data = "Vec3(X: " + std::to_string(x) + ", Y: " + std::to_string(y) + ", Z: " + std::to_string(z) + ").";
			return data;
		}
	};

	class vec4
	{
	public:
		float x;
		float y;
		float z;
		float w;

	public:
		const float* data() const
		{
			return &x;
		}

		std::string PrintData() const
		{
			std::string data = "Vec4(X: " + std::to_string(x) + ", Y: " + std::to_string(y) + ", Z: " + std::to_string(z) + ", W: " + std::to_string(w) + ").";
			return data;
		}
	};

	class mat4
	{
	private:
		float mat[16];

	public:
		mat4()
		{
			std::memset(mat, 0, sizeof(mat));
			mat[0 + 0 * 4] = 1.0f;
			mat[1 + 1 * 4] = 1.0f;
			mat[2 + 2 * 4] = 1.0f;
			mat[3 + 3 * 4] = 1.0f;
		}

		mat4 identity()
		{
			return mat4();
		}

		mat4 translate(vec3 vec)
		{
			mat4 result = identity();
			result.mat[0 + 3 * 4] = vec.x;
			result.mat[1 + 3 * 4] = vec.y;
			result.mat[2 + 3 * 4] = vec.z;
			return result;
		}

		mat4 scale(vec3 vec)
		{
			mat4 result = identity();
			result.mat[0 + 0 * 4] = vec.x;
			result.mat[1 + 1 * 4] = vec.y;
			result.mat[2 + 2 * 4] = vec.z;
			return result;
		}

		mat4 rotateZ(float angle)
		{
			mat4 result = identity();
			float cosinus = cos(angle);
			float sinus = sin(angle);
			
			result.mat[0 + 0 * 4] = cosinus;
			result.mat[0 + 1 * 4] =-sinus;
			result.mat[1 + 0 * 4] = sinus;
			result.mat[1 + 1 * 4] = cosinus;

			return result;
		}
	};
}
