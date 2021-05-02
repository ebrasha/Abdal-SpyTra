//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "hpage.h"
#include "ASVP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "acPNG"
#pragma resource "*.dfm"
TAlert *Alert;
//---------------------------------------------------------------------------
__fastcall TAlert::TAlert(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

