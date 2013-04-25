#ifndef IFSABSTRACT
# define IFSABSTRACT

# include <string>


class IFSAbstract
{
public:

  virtual bool		FSOpen(const std::string &sPath) = 0;
  virtual bool		FSClose() = 0;
  virtual int		FSRead(std::string &sBuff, int iLen) const = 0;
  virtual int		FSWrite(const std::string &buff) const = 0;
};


#endif // IFSABSTRACT
