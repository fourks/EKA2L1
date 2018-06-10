program EKA2L1;

{$mode objfpc}{$H+}{$M+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms, MainForm, APIWrapper, Symbian, dvcmapping;

{$R *.res}

begin
  RequireDerivedFormResource:=True;
  Application.Initialize;
  Application.CreateForm(TMainForm, EMainForm);
  Application.CreateForm(TDeviceMapper, DeviceMapper);
  Application.Run;
end.

