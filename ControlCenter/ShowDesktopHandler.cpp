#include "stdafx.h"
#include <Shldisp.h>
#include "ShowDesktopHandler.h"

ShowDesktopHandler::ShowDesktopHandler()
{
}

ShowDesktopHandler::~ShowDesktopHandler()
{
}

void ShowDesktopHandler::handle(std::string sentence)
{
	CoInitialize(NULL);

	IShellDispatch4 *pShellDisp = NULL;   
	HRESULT sc = CoCreateInstance( CLSID_Shell, NULL, CLSCTX_SERVER, IID_IDispatch, (LPVOID *) &pShellDisp );
	sc = pShellDisp->ToggleDesktop();

	pShellDisp->Release();
}