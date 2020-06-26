#include <vcl.h>
#pragma hdrstop
USERES("Benzin2.res");
USEFORM("cBeall.cpp", Beallit);
USEFORM("cFlsClear.cpp", FlsClr);
USEFORM("cVezerlo.cpp", Vezerlo);
USEFORM("cBenzMnt.cpp", BenzMent);
USEFORM("cCardKonv.cpp", CardKonv);
USEFORM("cEEpromInit.cpp", EEpromInit);
USEFORM("cOraBe.cpp", OraBe);
USEFORM("cNyomtato.cpp", NyomtatoTeszt);
USEFORM("cAnalog.cpp", Analog);
USEUNIT("cTxtBenzin.cpp");
USEUNIT("cUdpalap.cpp");
USEFORM("cSzintmero.cpp", Szintmero);
USEUNIT("cModBusSoros.cpp");
USEFORM("cTeszt.cpp", Teszt);
USEFORM("cKutfoTst.cpp", KutfoTst);
USEFORM("cTankTst.cpp", TankTst);
USEFORM("cUjKartyaBe.cpp", UjKartyaBe);
USEFORM("cCegnevek.cpp", Cegnevek);
USEFORM("cArak.cpp", Arak);
USEFORM("cGyurus.cpp", Gyurus);
USEFORM("cUpgrade.cpp", Upgrade);
USEFORM("cMemo.cpp", PrgMem);
USEFORM("cHexFile.cpp", HexFile);
USEFORM("cSzintTbl.cpp", SzintTbl);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
try{
  Application->Initialize();
  Application->Title = "Benzin vezérlõ szerviz program";
  Application->CreateForm(__classid(TVezerlo), &Vezerlo);
		Application->CreateForm(__classid(TBeallit), &Beallit);
		Application->CreateForm(__classid(TFlsClr), &FlsClr);
		Application->CreateForm(__classid(TBenzMent), &BenzMent);
		Application->CreateForm(__classid(TCardKonv), &CardKonv);
		Application->CreateForm(__classid(TEEpromInit), &EEpromInit);
		Application->CreateForm(__classid(TOraBe), &OraBe);
		Application->CreateForm(__classid(TNyomtatoTeszt), &NyomtatoTeszt);
		Application->CreateForm(__classid(TAnalog), &Analog);
		Application->CreateForm(__classid(TSzintmero), &Szintmero);
		Application->CreateForm(__classid(TTeszt), &Teszt);
		Application->CreateForm(__classid(TKutfoTst), &KutfoTst);
		Application->CreateForm(__classid(TTankTst), &TankTst);
		Application->CreateForm(__classid(TUjKartyaBe), &UjKartyaBe);
		Application->CreateForm(__classid(TCegnevek), &Cegnevek);
		Application->CreateForm(__classid(TArak), &Arak);
		Application->CreateForm(__classid(TGyurus), &Gyurus);
		Application->CreateForm(__classid(TUpgrade), &Upgrade);
		Application->CreateForm(__classid(TPrgMem), &PrgMem);
		Application->CreateForm(__classid(THexFile), &HexFile);
		Application->CreateForm(__classid(TSzintTbl), &SzintTbl);
		Application->Run();
  }
catch(Exception &exception){
  Application->ShowException(&exception);
  }
return 0;
}
//-------------------------------------
