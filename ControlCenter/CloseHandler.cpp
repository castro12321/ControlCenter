#include "stdafx.h"
#include "CloseHandler.h"
#include <fstream>
#include <Windows.h>
#include <TlHelp32.h>
#include <unordered_map>

CloseHandler::CloseHandler()
{
}


CloseHandler::~CloseHandler()
{
}


// Returns Map<ProgramName, ProcessName>
std::unordered_map<std::string, std::string> getProcessesMap()
{
	std::unordered_map<std::string, std::string> processNamesByProgramNames;

	std::fstream processes("programs/processes.txt", std::ios::in);

	if (processes.good())
	{
		std::string line;
		getline(processes, line);
		while (!processes.eof())
		{
			std::vector<std::string> splitted = Utils::split(line, '=');
			std::string programName = splitted[0];
			std::string processName = splitted[1];
			processNamesByProgramNames.emplace(programName, processName);

			getline(processes, line);
		}
	}
	else
		std::cout << "cannot open processes map";

	return processNamesByProgramNames;
}


DWORD GetProcID(std::string processName)
{
	std::wstring ProcName = std::wstring(processName.begin(), processName.end());
	PROCESSENTRY32 PE32;
	HANDLE ProcSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	PE32.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(ProcSnapshot, &PE32))
		return 0;
	else
	if (PE32.szExeFile == ProcName)
		return PE32.th32ProcessID;
	else
	{
		while (GetLastError() != ERROR_NO_MORE_FILES){
			Process32Next(ProcSnapshot, &PE32);
			if (PE32.szExeFile == ProcName)
				return PE32.th32ProcessID;
		}
		return 0;
	}
}


// Callback Enum Function.
BOOL CALLBACK TerminateAppEnum(HWND hwnd, LPARAM lParam)
{
	DWORD dwID;

	GetWindowThreadProcessId(hwnd, &dwID);

	if (dwID == (DWORD)lParam)
		PostMessage(hwnd, WM_CLOSE, 0, 0);

	return TRUE;
}


#define TA_FAILED 0
#define TA_SUCCESS_CLEAN 1
#define TA_SUCCESS_KILL 2


/*----------------------------------------------------------------
DWORD WINAPI TerminateApp( DWORD dwPID, DWORD dwTimeout )

Purpose:
Shut down a 32-Bit Process (or 16-bit process under Windows 95)

Parameters:
dwPID
Process ID of the process to shut down.

dwTimeout
Wait time in milliseconds before shutting down the process.

Return Value:
TA_FAILED - If the shutdown failed.
TA_SUCCESS_CLEAN - If the process was shutdown using WM_CLOSE.
TA_SUCCESS_KILL - if the process was shut down with
TerminateProcess().
NOTE:  See header for these defines.
----------------------------------------------------------------*/
DWORD WINAPI TerminateApp(DWORD dwPID, DWORD dwTimeout)
{
	HANDLE  hProc;
	DWORD   dwRet;

	// If we can't open the process with PROCESS_TERMINATE rights, then we give up immediately.
	hProc = OpenProcess(SYNCHRONIZE | PROCESS_TERMINATE, FALSE,
		dwPID);

	if (hProc == NULL)
		return TA_FAILED;

	// TerminateAppEnum() posts WM_CLOSE to all windows whose PID matches your process's.
	EnumWindows((WNDENUMPROC)TerminateAppEnum, (LPARAM)dwPID);

	// Wait on the handle. If it signals, great. If it times out, then you kill it.
	if (WaitForSingleObject(hProc, dwTimeout) != WAIT_OBJECT_0)
		dwRet = TA_FAILED;// dwRet = (TerminateProcess(hProc, 0) ? TA_SUCCESS_KILL : TA_FAILED);
	else
		dwRet = TA_SUCCESS_CLEAN;

	CloseHandle(hProc);

	return dwRet;
}


void CloseHandler::handle(std::string sentence)
{
	std::vector<std::string> toClose = Utils::split(sentence, ' ', 1);
	if (toClose.size() < 2)
		return synthesizer.say("Please provide a program to close");
	std::string programName = toClose[1];

	std::string processName = getProcessesMap().at(programName);
	std::cout << "Closing " << programName << " processName: " << processName << "\n";
	DWORD PID = GetProcID(processName);
	std::cout << "Found PID: " << PID;
	TerminateApp(PID, 5000);
}
