#pragma once
#include "DngPattern.h"
#include <string>
#include <vector>
class DngImage
{
public:
	DngImage(const std::string& path);
    DngImage(const char* data,size_t size);
	DngImage(DngImage&& dng);
	DngImage(const DngImage& dng);
	DngImage& operator=(const DngImage& dng);
	DngImage& operator=(DngImage&& dng);
	~DngImage(){}
	inline int GetWidth()const { return m_Width; }
	inline int GetHeight()const { return m_Height; }
	inline int GetBitsPerPixel()const { return m_BitsPerPixel; }
	inline DngPattern GetPattern()const { return m_Pattern; }
	inline const unsigned char* GetData()const { return m_Data.data(); }
private:
	int m_Width;
	int m_Height;
	int m_BitsPerPixel;
	DngPattern m_Pattern;
	std::vector<unsigned char> m_Data;
};