#include <vcl.h>
#pragma hdrstop

USEFORM("MainUnit.cpp", Main);
USEFORM("CaptureUnit.cpp", Capture);
USEFORM("GridUnit.cpp", CoordGrid);

USERC("WinSizeRc.rc");
USERES("WinSize.res");

WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try {
    Application->Initialize();
    Application->Title = "WinSize 2.0";

    Application->CreateForm(__classid(TMain), &Main);
    Application->CreateForm(__classid(TCapture), &Capture);

    Application->Run();
  }
  catch (Exception &exception) {
    Application->ShowException(&exception);
  }
  return 0;
}
