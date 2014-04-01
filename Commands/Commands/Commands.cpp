#include <Windows.h>
#include "Commands.h"

Commands::Commands(std::string value)
{
	sentence = value;
}

Commands::~Commands()
{
}

void Commands::runProgram()
{
	std::cout << "Trying to recognize sentence: " << sentence << "\n";

	std::smatch result;

	static const std::regex NEW_TAB("^new tab");
	if (std::regex_search(sentence, result, NEW_TAB))
		ShellExecute(0, "open", "new_tab.exe", "", "", SW_SHOWNORMAL);

	static const std::regex CLOSE_TAB("^close tab");
	if (std::regex_search(sentence, result, CLOSE_TAB))
		ShellExecute(0, "open", "close_tab.exe", "", "", SW_SHOWNORMAL);

	static const std::regex WINDOW_CLOSE1("^close (active|current)"), WINDOW_CLOSE2("^window close");
	if (std::regex_search(sentence, result, WINDOW_CLOSE1)
		|| std::regex_search(sentence, result, WINDOW_CLOSE2))
		ShellExecute(0, "open", "close_window.exe", "", "", SW_SHOWNORMAL);

	static const std::regex WINDOW_MINIMIZE1("^window minimize"), WINDOW_MINIMIZE2("^minimize");
	if (std::regex_search(sentence, result, WINDOW_MINIMIZE1)
		|| std::regex_search(sentence, result, WINDOW_MINIMIZE2))
		ShellExecute(0, "open", "minimize_window.exe", "", "", SW_SHOWNORMAL);

	static const std::regex WINDOW_MAXIMIZE1("^window maximize"), WINDOW_MAXIMIZE2("^maximize");
	if (std::regex_search(sentence, result, WINDOW_MAXIMIZE1)
		|| std::regex_search(sentence, result, WINDOW_MAXIMIZE2))
		ShellExecute(0, "open", "maximize_window.exe", "", "", SW_SHOWNORMAL);

	static const std::regex OPEN_PROGRAM("^open .*");
	if (std::regex_search(sentence, result, OPEN_PROGRAM))
		ShellExecute(0, "open", "open.exe", "", "", SW_SHOWNORMAL);

	static const std::regex CLOSE_PROGRAM("^close .*");
	if (std::regex_search(sentence, result, CLOSE_PROGRAM))
		ShellExecute(0, "open", "close.exe", "", "", SW_SHOWNORMAL);

	static const std::regex SAY_TIME1("^say time"), SAY_TIME2("^time");
	if (std::regex_search(sentence, result, SAY_TIME1)
		|| std::regex_search(sentence, result, SAY_TIME2))
		ShellExecute(0, "open", "say_time.exe", "", "", SW_SHOWNORMAL);

	static const std::regex SAY_DATE1("^say date"), SAY_DATE2("^date");
	if (std::regex_search(sentence, result, SAY_DATE1)
		|| std::regex_search(sentence, result, SAY_DATE2))
		ShellExecute(0, "open", "say_date.exe", "", "", SW_SHOWNORMAL);

	static const std::regex REFRESH("^refresh");
	if (std::regex_search(sentence, result, REFRESH))
		ShellExecute(0, "open", "refresh.exe", "", "", SW_SHOWNORMAL);

	static const std::regex CREATE_DIR("^(create|new) directory");
	if (std::regex_search(sentence, result, CREATE_DIR))
		ShellExecute(0, "open", "new_directory.exe", "", "", SW_SHOWNORMAL);

	static const std::regex CREATE_FILE("^(create|new) file");
	if (std::regex_search(sentence, result, CREATE_FILE))
		ShellExecute(0, "open", "new_file.exe", "", "", SW_SHOWNORMAL);

	static const std::regex SHOW_DESKTOP("^show desktop");
	if (std::regex_search(sentence, result, SHOW_DESKTOP))
		ShellExecute(0, "open", "show_desktop.exe", "", "", SW_SHOWNORMAL);

	static const std::regex ZOOM_IN("^zoom in");
	if (std::regex_search(sentence, result, ZOOM_IN))
		ShellExecute(0, "open", "zoom_in.exe", "", "", SW_SHOWNORMAL);

	static const std::regex ZOOM_OUT("^zoom out");
	if (std::regex_search(sentence, result, ZOOM_OUT))
		ShellExecute(0, "open", "zoom_out.exe", "", "", SW_SHOWNORMAL);

	static const std::regex ZOOM_RESET("^zoom reset");
	if (std::regex_search(sentence, result, ZOOM_RESET))
		ShellExecute(0, "open", "zoom_reset.exe", "", "", SW_SHOWNORMAL);

	//synthesizer.say("Sorry I don't know this command"); // Sorry, but it freezes the app :<
	std::cout << "Nothing found! Returning nullptr :<\n";
}
