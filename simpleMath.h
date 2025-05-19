#pragma once

#include <cmath>
#include <string>
#include <cstring>
#include <iostream>

namespace math
{
	constexpr float PI = 3.14159265f;

	constexpr static float ToRadians(float degrees)
	{
		return degrees * (PI / 180.0f);
	}

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

	static vec3 cross(const vec3& other1, const vec3& other2)
	{
		vec3 result = vec3();
		result.x = other1.y * other2.z - other1.z * other2.y;
		result.y = other1.z * other2.x - other1.x * other2.z;
		result.z = other1.x * other2.y - other1.y * other2.x;
		return result;
	}

	static vec3 normalize(const vec3& vec)
	{
		float len = vec.length();
		return (len == 0) ? vec3() : vec3(vec.x / len, vec.y / len, vec.z / len);
	}

	class vec4
	{
	public:
		float vec[4];

	public:
		vec4()
		{ 
			vec[0] = 0.0f;
			vec[1] = 0.0f;
			vec[2] = 0.0f;
			vec[3] = 0.0f;
		}

		vec4(float _x, float _y, float _z, float _w)
		{
			vec[0] = _x;
			vec[1] = _y;
			vec[2] = _z;
			vec[3] = _w;
		}

		const float* data() const
		{
			return &vec[0];
		}

		std::string PrintData() const
		{
			std::string data = "Vec4(X: " + std::to_string(vec[0]) + ", Y: " + std::to_string(vec[1]) + ", Z: " + std::to_string(vec[2]) + ", W: " + std::to_string(vec[3]) + ").";
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

		mat4 operator*(const mat4& other)
		{
			mat4 result = mat4();
			
			for (int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
				{
					result.mat[col + row * 4] =
						mat[0 + row * 4] * other.mat[col + 0 * 4] +
						mat[1 + row * 4] * other.mat[col + 1 * 4] +
						mat[2 + row * 4] * other.mat[col + 2 * 4] +
						mat[3 + row * 4] * other.mat[col + 3 * 4];
				}
			}
			return result;

			return result;
		}

		float& operator[](int i)
		{
			return mat[i];
		}

		const float* data() const
		{
			return &mat[0];
		}
	}; 
	
	static mat4 perspective(float fovInRadians, float aspectRatio, float near, float far)
	{
		mat4 result = mat4();

		result[0 + 0 * 4] = 1.0f / (aspectRatio * tanf(fovInRadians / 2.0f));
		result[1 + 1 * 4] = 1.0f / (tanf(fovInRadians / 2.0f));
		result[2 + 2 * 4] = -((far + near) / (far - near));
		result[2 + 3 * 4] = -((2.0f * far * near) / (far - near));
		result[3 + 2 * 4] = -1.0f;
		result[3 + 3 * 4] = 0.0f;

		return result;
	}

	static mat4 orthographic(float left, float right, float bottom, float top, float far = 0.0f, float near = 1.0f)
	{
		mat4 result = mat4();

		result[0 + 0 * 4] = 2.0f / (right - left);
		result[1 + 1 * 4] = 2.0f / (top - bottom);
		result[2 + 2 * 4] = -2.0f / (far - near);

		result[3 + 0 * 4] = -(right + left) / (right - left);
		result[3 + 1 * 4] = -(top + bottom) / (top - bottom);
		result[3 + 2 * 4] = - near / (far - near);

		return result;
	}

	static mat4 lookAt(const vec3& eye, const vec3& target, const vec3& upVec)
	{
		vec3 forward = normalize(target - eye);
		vec3 right = normalize(cross(upVec, forward));
		vec3 up = cross(forward, right);

		mat4 orientation = mat4();
		orientation[0 + 0 * 4] = right.x;
		orientation[0 + 1 * 4] = up.x;
		orientation[0 + 2 * 4] = forward.x;

		orientation[1 + 0 * 4] = right.y;
		orientation[1 + 1 * 4] = up.y;
		orientation[1 + 2 * 4] = forward.y;

		orientation[2 + 0 * 4] = right.z;
		orientation[2 + 1 * 4] = up.z;
		orientation[2 + 2 * 4] = forward.z;

		mat4 translation = mat4();
		translation[3 + 0 * 4] = -eye.x;
		translation[3 + 1 * 4] = -eye.y;
		translation[3 + 2 * 4] = -eye.z;

		return (orientation * translation);
	}
	
	static mat4 translate(vec3 vec)
	{
		mat4 result = mat4();
		result[0 + 3 * 4] = vec.x;
		result[1 + 3 * 4] = vec.y;
		result[2 + 3 * 4] = vec.z;
		return result;
	}

	static mat4 translate(vec2 vec)
	{
		mat4 result = mat4();
		result[0 + 3 * 4] = vec.x;
		result[1 + 3 * 4] = vec.y;
		result[2 + 3 * 4] = 0.0f;
		return result;
	}

	static mat4 scale(vec3 vec)
	{
		mat4 result = mat4();
		result[0 + 0 * 4] = vec.x;
		result[1 + 1 * 4] = vec.y;
		result[2 + 2 * 4] = vec.z;
		return result;
	}

	static mat4 scale(vec2 vec)
	{
		mat4 result = mat4();
		result[0 + 0 * 4] = vec.x;
		result[1 + 1 * 4] = vec.y;
		result[2 + 2 * 4] = 1.0f;
		return result;
	}

	static mat4 rotate(const vec3& axis, float angle)
	{
		vec3 normalizedAxis = normalize(axis);
		float cosinus = cos(angle);
		float sinus = sin(angle);
		float oneMinusCosA = 1.0f - cosinus;

		float x = normalizedAxis.x;
		float y = normalizedAxis.y;
		float z = normalizedAxis.z;

		mat4 result = mat4();

		result[0 + 0 * 4] = cosinus + x * x * oneMinusCosA;
		result[0 + 1 * 4] = x * y * oneMinusCosA - z * sinus;
		result[0 + 2 * 4] = x * z * oneMinusCosA + y * sinus;

		result[1 + 0 * 4] = y * x * oneMinusCosA + z * sinus;
		result[1 + 1 * 4] = cosinus + y * y * oneMinusCosA;
		result[1 + 2 * 4] = y * z * oneMinusCosA - x * sinus;

		result[2 + 0 * 4] = z * x * oneMinusCosA - y * sinus;
		result[2 + 1 * 4] = z * y * oneMinusCosA + x * sinus;
		result[2 + 2 * 4] = cosinus + z * z * oneMinusCosA;

		return result;
	}
}
