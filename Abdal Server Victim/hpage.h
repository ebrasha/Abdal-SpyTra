//---------------------------------------------------------------------------

#ifndef hpageH
#define hpageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "acPNG.hpp"
//---------------------------------------------------------------------------
class TAlert : public TForm
{
__published:	// IDE-managed Components
	TImage *enImage;
	TImage *faImage;
private:	// User declarations
public:		// User declarations
	__fastcall TAlert(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAlert *Alert;
//---------------------------------------------------------------------------
#endif
