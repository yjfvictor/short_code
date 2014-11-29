#include <windows.h>

#ifndef EWX_FORCEIFHUNG
#define EWX_FORCEIFHUNG 0x00000010
#endif

int main(void)
{
	HANDLE token;
	TOKEN_PRIVILEGES tp;
	if(OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token))
	{
		LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &(tp.Privileges[0].Luid));
		tp.PrivilegeCount = 1;
		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		AdjustTokenPrivileges(token, FALSE, &tp, 0, NULL, 0);
	}
	ExitWindowsEx(EWX_FORCE | EWX_SHUTDOWN | EWX_POWEROFF | EWX_FORCEIFHUNG, 0);
	return 0;
}
