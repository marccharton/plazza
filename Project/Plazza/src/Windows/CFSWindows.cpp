#include <Windows.h>

#include <iostream>
#include <algorithm>

#include "CFSWindows.hpp"


bool	CFSWindows::FSOpen(const std::string &sPath)
{
  std::wstring  wsPath = StringToWString(sPath);

  HANDLE	hFile = CreateFileA(sPath.c_str(),
							   GENERIC_READ | GENERIC_WRITE,
							   FILE_SHARE_READ,
							   NULL,
							   OPEN_EXISTING,
							   FILE_ATTRIBUTE_NORMAL,
							   NULL
					);

  if (hFile == INVALID_HANDLE_VALUE)
    {
      std::cerr << "[ERROR] Could not open the file" << std::endl;
      return false;
    }
  std::cout << ">>> [WINDOWS] File opended" << std::endl;
  this->hdl_ = hFile;
  return true;
}


bool	CFSWindows::FSClose()
{
  if (CloseHandle(this->hdl_) == false)
    {
      std::cerr << "[ERROR] Could not close the file" << std::endl;
      return false;
    }
  std::cout << ">>> [WINDOWS] File closed" << std::endl;
  return true;
}


int	CFSWindows::FSRead(std::string &sBuff, int iLen) const
{
  char 	*tmpBuff = new char [iLen + 1];
  DWORD	nbRead;

  if (ReadFile(this->hdl_, tmpBuff, iLen, &nbRead, NULL) == 0)
    {
      std::cerr << "[ERROR] Could not read the file" << std::endl;
      return -1;
    }
  tmpBuff[nbRead] = 0;
  sBuff = tmpBuff;
  delete [] tmpBuff;
  std::cout << ">>> [WINDOWS] File read:" << std::endl << sBuff << "<<< [" << nbRead << "] char read" << std::endl;
  return nbRead;
}


int	CFSWindows::FSWrite(const std::string &buff) const
{
  DWORD	nbWritten;

  if (WriteFile(this->hdl_, (LPCVOID) buff.c_str(), buff.length(), &nbWritten, NULL) == 0)
    {
      std::cerr << "[WINDOWS] Could not write the file" << std::endl;
      return -1;
    }
  std::cout << ">>> [WINDOWS] File written:" << std::endl << buff << "<<< [" << nbWritten << "] char written" << std::endl;
  return nbWritten;
}


std::wstring StringToWString(const std::string& s)
{
  std::wstring temp(s.length(),L' ');
  std::copy(s.begin(), s.end(), temp.begin());
  return temp;
}
