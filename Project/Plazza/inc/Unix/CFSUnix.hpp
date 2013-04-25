#ifndef CFSUNIX
# define CFSUNIX

# include <string>

# include "IFSAbstract.h"


class CFSUnix : public IFSAbstract
{
 private:

  int		fd_;

 public:

  virtual bool	FSOpen(const std::string &sPath);
  virtual bool	FSClose();
  virtual int	FSRead(std::string &sBuff, int iLen) const;
  virtual int	FSWrite(const std::string &buff) const;
};


#endif //CFSUNIX
