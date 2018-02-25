// standard library
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <exception>
#include <memory>
#include <cstddef>
#include <cstring>

// boost
#include <boost/format.hpp>
#include <boost/system/system_error.hpp>

// header
#include "class.h"

// using
using namespace std;
using namespace dfs_lte;
using namespace boost;

int wmain(int argc, wchar_t** argv)
{
	try
	{
		wcout.imbue(locale(""));
		wcerr.imbue(locale(""));
		wcin.imbue(locale(""));

		if(argc == 1)
		{
			wcout << L"open file?(Y/N)" << endl;
			while(true)
			{
				wchar_t YorN;
				wcout << L'>';
				wcin >> YorN;

				YorN = static_cast<wchar_t>(
							towlower(
								static_cast<wint_t>(YorN)
							)
				);
				switch(YorN)
				{
				case L'y':
					{
						wstring filename;
						wcout << L"filename: ";
						getline(wcin, filename);

						CommandLine(filename);
					}

				case L'n':
					{
						File file;
						CommandLine(file);
					}

				default: continue;
				}
			}
		}
		else if(argc == 2)
			CommandLine(argv[1]);
		else
		{
			wcerr << wformat(L"usage: %1% <filename>") % argv[0] << endl;
			return EXIT_FAILURE;
		}
	}
	catch(boost::system::system_error& e)
	{
		const char*		mess_c		= e.what();
		const size_t		mess_len	= strlen(mess_c);
		unique_ptr<wchar_t[]>	mess(new wchar_t[mess_len + 1]);
		mbstowcs(mess.get(), mess_c, mess_len);

		wcerr << L"error:" << endl;
		wcerr << mess.get() << endl;
		wcerr << wformat(L"(error code: %1%)") % e.code().value() << endl;
	}
	catch(std::exception& e)
	{
		const char*		mess_c		= e.what();
		const size_t		mess_len	= strlen(mess_c);
		unique_ptr<wchar_t[]>	mess(new wchar_t[mess_len + 1]);
		mbstowcs(mess.get(), mess_c, mess_len);

		wcerr << L"error:" << endl;
		wcerr << mess.get() << endl;
	}
	catch(dfs_lte::exception& e)
	{
		wcerr << L"error:" << endl;
		wcerr << e.getMessage() << endl;
	}

	return EXIT_FAILURE;
}
