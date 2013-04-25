#ifndef CFSWINDOWS
# define CFSWINDOWS

# include <Windows.h>
# include <string>

# include "IFSAbstract.hpp"


std::wstring	StringToWString(const std::string& s);

class CFSWindows : public IFSAbstract
{
	private:
		HANDLE		hdl_;
	public:
		virtual bool	FSOpen(const std::string &sPath);
		virtual bool	FSClose();
		virtual int	FSRead(std::string &sBuff, int iLen) const;
		virtual int	FSWrite(const std::string &buff) const;
};


#endif //CFSWINDOWS
