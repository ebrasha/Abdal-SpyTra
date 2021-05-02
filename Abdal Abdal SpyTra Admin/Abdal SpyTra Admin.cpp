
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("ASTAP.cpp", FormEchoclientf);
USEFORM("MonASTAP.cpp", MonASTA);
//---------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
       Application->Initialize();

       TStyleManager::TrySetStyle("Windows10");
		Application->CreateForm(__classid(TFormEchoclientf), &FormEchoclientf);
		Application->CreateForm(__classid(TMonASTA), &MonASTA);
		Application->Run();
   }
   catch (Exception &exception)
   {
       Application->ShowException(&exception);
   }
   return 0;
}
//---------------------------------------------------------------------------


