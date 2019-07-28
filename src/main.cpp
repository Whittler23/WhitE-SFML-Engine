
#include <stdexcept>

//TODO: Macro should be handled by own macro

#ifdef _WIN32
#include <Windows.h>
#endif

void showMessageBox(const std::string& str)
{
	MessageBoxA(nullptr, str.c_str(), "Error", MB_OK | MB_ICONERROR);
}

int main()
{
try {
	
}
catch (std::runtime_error & e)
{
	showMessageBox(e.what());
	throw;
}
catch (...)
{
	showMessageBox("Unknown Error!");
	throw;
}
}