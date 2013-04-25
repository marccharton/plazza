#include <iostream>
#include <fcntl.h>
#include <unistd.h>

#include "CFSUnix.hpp"


bool	CFSUnix::FSOpen(const std::string &sPath)
{
  int fd = open(sPath.c_str(), O_RDWR);
  if (fd == -1)
    {
      std::cerr << "[ERROR] Could not open the file" << std::endl;
      return false;
    }
  std::cout << ">>> [UNIX] File opended" << std::endl;
  this->fd_ = fd;
  return true;
}

bool	CFSUnix::FSClose()
{
  if (close(this->fd_) == -1)
    {
      std::cerr << "[ERROR] Could not close the file" << std::endl;
      return false;
    }
  std::cout << ">>> [UNIX] File closed" << std::endl;
  return true;
}

int	CFSUnix::FSRead(std::string &sBuff, int iLen) const
{
  char tmpBuff[iLen + 1];

  int nbRead = read(this->fd_, tmpBuff, iLen);
  if (nbRead == -1)
    {
      std::cerr << "[ERROR] Could not read the file" << std::endl;
      return -1;
    }
  tmpBuff[nbRead] = 0;
  sBuff = tmpBuff;
  std::cout << ">>> [UNIX] File read:" << std::endl << sBuff << "<<< [" << nbRead << "] char read" << std::endl;
  return nbRead;
}

int	CFSUnix::FSWrite(const std::string &buff) const
{
  int nbWritten = write(this->fd_, buff.c_str(), buff.length());
  if (nbWritten == -1)
    {
      std::cerr << "[ERROR] Could not write the file" << std::endl;
      return -1;
    }
  std::cout << ">>> [UNIX] File written:" << std::endl << buff << "<<< [" << nbWritten << "] char written" << std::endl;
  return nbWritten;
}
