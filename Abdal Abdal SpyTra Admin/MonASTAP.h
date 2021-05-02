//---------------------------------------------------------------------------

#ifndef MonASTAPH
#define MonASTAPH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TMonASTA : public TForm
{
__published:	// IDE-managed Components
	TListBox *mon;
private:	// User declarations
public:		// User declarations
	__fastcall TMonASTA(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMonASTA *MonASTA;
//---------------------------------------------------------------------------
#endif
