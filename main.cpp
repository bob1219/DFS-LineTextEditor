// standard library
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <exception>
#include <memory>
#include <cstddef>
#include <cstring>
#include <clocale>

// boost
#include <boost/format.hpp>
#include <boost/system/system_error.hpp>

// header
#include "exception.h"
#include "File.h"
#include "function.h"
#include "Files.h"

// using
using namespace std;
using namespace dfs_lte;
using namespace boost;

int wmain(int argc, wchar_t** argv)
{
	try
	{
		// Setting locale
		wcout.imbue(locale{""});
		wcerr.imbue(locale{""});
		wcin.imbue(locale{""});
		setlocale(LC_ALL, "");

		if(argc == 1)
		{
			wcout << L"open file?(Y/N)" << endl;
			while(true)
			{
				wchar_t YorN;
				wcout << L'>';
				wcin >> YorN;
				wcin.ignore();

				wstring filename;
				YorN = towlower(YorN);
				switch(YorN)
				{
				case L'y':
					wcout << L"filename: ";
					getline(wcin, filename);

					wcout << endl;
					welcome();
					CommandLine(Files{File{filename}});

				case L'n':
					wcout << endl;
					welcome();
					CommandLine(Files{File{}});

				default: continue;
				}
			}
		}
		else if(argc == 2)
		{
			welcome();
			CommandLine(Files{File{argv[1]}});
		}
		else
		{
			wcerr << wformat{L"usage: %1% <filename>"} % argv[0] << endl;
			return EXIT_FAILURE;
		}
	}
	catch(boost::system::system_error& e)
	{
		const auto		mess_c		= e.what();
		const auto		mess_len	= strlen(mess_c);
		unique_ptr<wchar_t[]>	mess{new wchar_t[mess_len + 1]};
		mbstowcs(mess.get(), mess_c, mess_len);

		wcerr << L"error:" << endl;
		wcerr << mess.get() << endl;
		wcerr << wformat(L"(error code: %1%)") % e.code().value() << endl;
	}
	catch(std::exception& e)
	{
		const auto		mess_c		= e.what();
		const auto		mess_len	= strlen(mess_c);
		unique_ptr<wchar_t[]>	mess{new wchar_t[mess_len + 1]};
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
