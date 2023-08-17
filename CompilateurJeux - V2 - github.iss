

#define MyAppName ""
#define MyAppVersion "2.0"
#define MyAppPublisher ""
#define MyAppURL "https://corentin-k.github.io/site.io/"
#define MyAppExeName "Cplusplus.exe"
#define MyAppExeName2 ""
#define MyAppAssocName MyAppName + " File"
#define MyAppAssocExt ".myp"
#define MyAppAssocKey StringChange(MyAppAssocName, " ", "") + MyAppAssocExt
#define imageBMP   " xxx .bmp"
[Setup]


AppId={{}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\{#MyAppName}                             
ChangesAssociations=yes
DefaultGroupName={#MyAppName}
AllowNoIcons=yes
  MissingMessagesWarning=yes
NotRecognizedMessagesWarning=yes
InfoAfterFile="xxx.txt"


OutputDir=chemin pour l'exe
OutputBaseFilename=COCO
SetupIconFile=xxx.ico
Password=xxx
Compression=lzma2
SolidCompression=yes
WizardStyle=modern
WizardImageFile={#imageBMP}
WizardSmallImageFile={#imageBMP}

LicenseFile="xxxx.txt"
[Languages]
Name: "en"; MessagesFile: "compiler:Default.isl"
Name: "fr"; MessagesFile: "compiler:Languages\French.isl"
 



[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked




[Files]
Source: "lien vers {#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion;  Check: MyProgCheck(1);
 ;Source: "MyProg.chm"; DestDir: "{app}"; Languages: en

Source: "lien vers libgcc_s_seh-1.dll"; DestDir: "{app}" ;     Check: MyProgCheck(2);
Source: "lien vers libstdc++-6.dll"; DestDir: "{app}"      ;  Check: MyProgCheck(3);
Source: "lien vers libwinpthread-1.dll"; DestDir: "{app}"   ;Check: MyProgCheck(4);
;Source: "{code:GetSelectedExe}";DestDir:"{app}";Flags:ignoreversion;
Source: lien vers xx.txt ;  DestDir: "{app}"
Source: "lien vers xxxx.exe"; DestDir: "{app}"; Flags: ignoreversion; Check: MyProgCheck(6);
Source:  "lien vers xxx.bmp"   ;   DestDir: "{tmp}"  

[Registry]
Root: HKA; Subkey: "Software\Classes\{#MyAppAssocExt}\OpenWithProgids"; ValueType: string; ValueName: "{#MyAppAssocKey}"; ValueData: ""; Flags: uninsdeletevalue
Root: HKA; Subkey: "Software\Classes\{#MyAppAssocKey}"; ValueType: string; ValueName: ""; ValueData: "{#MyAppAssocName}"; Flags: uninsdeletekey

Root: HKA; Subkey: "Software\Classes\{#MyAppAssocKey}\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\{#MyAppExeName},0" ;Check: MyProgCheck(1);
Root: HKA; Subkey: "Software\Classes\{#MyAppAssocKey}\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\{#MyAppExeName}"" ""%1""" ;Check: MyProgCheck(1);
Root: HKA; Subkey: "Software\Classes\Applications\{#MyAppExeName}\SupportedTypes"; ValueType: string; ValueName: ".myp"; ValueData: ""    ;Check: MyProgCheck(1);

Root: HKA; Subkey: "Software\Classes\{#MyAppAssocKey}\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\{#MyAppExeName2},0" ;Check: MyProgCheck(1);
Root: HKA; Subkey: "Software\Classes\{#MyAppAssocKey}\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\{#MyAppExeName2}"" ""%1""" ;Check: MyProgCheck(1);
Root: HKA; Subkey: "Software\Classes\Applications\{#MyAppExeName2}\SupportedTypes"; ValueType: string; ValueName: ".myp"; ValueData: ""    ;Check: MyProgCheck(1);


[Icons]
Name: "{group}\Cplusplus"; Filename: "{app}\{#MyAppExeName}" ;Check: MyProgCheck(1);
Name: "{group}\Projet_C"; Filename: "{app}\Projet_C.exe" ;Check: MyProgCheck(6);
Name: "{group}\AIDE"; Filename: "{app}\Info Apres.txt";   Languages: en
Name: "{group}\{cm:ProgramOnTheWeb,{#MyAppName}}"; Filename: "{#MyAppURL}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon; Check: MyProgCheck(1);
 
[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange('Cplusplus', '&', '&&')}}"; Flags: nowait postinstall skipifsilent ;  Check: MyProgCheck(1);
Filename: "{app}\Projet_C.exe"; Description: "{cm:LaunchProgram,{#StringChange('Projet_C', '&', '&&')}}"; Flags: nowait postinstall skipifsilent ;  Check: MyProgCheck(6);



[Code]

var
bitmap : string;
ResultCode: Integer;
  
  Page: TWizardPage;
 
  CheckListBox: TNewCheckListBox;
  CheckboxStates: array of Boolean;

  Label1: TLabel;
  Label2: TLabel;
  Label3: TLabel;
  WelcomeImage: TBitmapImage;
 



procedure CreateTheWizardPages;

begin
    
    
    
    
    Page := CreateCustomPage(wpWelcome, 'Bienvenue dans l''installateur des jeux de Coco', '');
    // Ici, vous pouvez ajouter des éléments à votre page, comme des labels, des images, etc.
    Label1 := TLabel.Create(WizardForm);
    Label1.Parent := Page.Surface;
    Label1.Left := 280 // Position horizontale du label
    Label1.Top := 80; // Position verticale du label
         Label1.Alignment := taCenter;
    Label1.Font.Name := 'Arial';
    Label1.Font.Size := 11;
    Label1.Font.Color := clRed;
    Label1.Caption := 'Vous allez avoir la possibilité d''installer 2 jeux : '; // Texte du label

    Label2 := TLabel.Create(WizardForm);
    Label2.Parent := Page.Surface;
    Label2.Left :=280;
    Label2.Top := 160;
    Label2.Font.Color:=clBlack;
    Label2.Font.Size := 10;  
    Label2.Caption := ' - Le jeu {#MyAppExeName}:'             + #13#10 + + #13#10 +
                      '     Ce jeu a été réalisé en août 2023 '+ #13#10 +
                      '     et créé en language C++'           + #13#10 ;
    
    Label3 := TLabel.Create(WizardForm);
    Label3.Font.Color:=clBlack    ;
    Label3.Font.Size := 10;
    Label3.Parent := Page.Surface;
    Label3.Left :=280;
    Label3.Top := 300;
    Label3.Caption := ' - Le jeu Projet_c.exe :'                                   + #13#10 ++ #13#10 +
                      '     Ce jeu a été réalisé au semestre 2 de L1 2023 '+ #13#10 +
                      '     et créé en language C.'                                + #13#10 +
                      '     C''est une application de dessin vectorielle';

    // Créer l'image et la configurer

    ExtractTemporaryFile('c++.bmp');
    bitmap := ExpandConstant('{tmp}\c++.bmp');
    WelcomeImage := TBitmapImage.Create(WizardForm);
    WelcomeImage.Parent := Page.Surface;
    WelcomeImage.Left := 0;
    WelcomeImage.Top := 100;
    WelcomeImage.Width := 256;
    WelcomeImage.Height := 256;
    WelcomeImage.Bitmap.LoadFromFile(bitmap);
  
                                                                                                                                   
  { TNewCheckListBox }

  Page := CreateCustomPage(Page.ID, 'Choisissez les jeux à installer :', '');
  
  CheckListBox := TNewCheckListBox.Create(Page);
  CheckListBox.Width := Page.SurfaceWidth;
  CheckListBox.Height := 500
  CheckListBox.Anchors := [akLeft, akTop, akRight, akBottom];
  CheckListBox.Flat := True;
  CheckListBox.Parent := Page.Surface;

  CheckListBox.AddCheckBox(' Cplusplus GAME', '', 0, True, True, False, True, nil);
    
    CheckListBox.AddCheckBox('Cplusplus.exe', '', 1, True, True, False, True, nil);
    CheckListBox.AddCheckBox('Cplusplus DLL', '', 1, True, True, False, True, nil);
      CheckListBox.AddCheckBox('DLL 1 : libstdc++-6', '', 2, True, True, False, True, nil);
      CheckListBox.AddCheckBox('DLL 2 : libwinpthread-1', '', 2, True, True, False, True, nil);
      CheckListBox.AddCheckBox('DLL 3 : libgcc_s_seh-1', '', 2, True, True, False, True, nil)

  CheckListBox.AddCheckBox('Dessin Vectoriel', '', 0, True, True, False, True, nil);
  CheckListBox.AddCheckBox('Projet_C.exe', '', 1, False, True, False, True, nil);


  CheckListBox.ItemFontStyle[0] := [fsBold];
  CheckListBox.SubItemFontStyle[5] := [fsBold];
  CheckListBox.ItemFontStyle[6] := [fsBold];
  CheckListBox.SubItemFontStyle[6] := [fsBold, fsUnderline];
  

  

end;



function NextButtonClick(CurPageID: Integer): Boolean;
var
  I: Integer;
begin
  if CurPageID = 101 then
  begin
    // Mettre à jour les états des cases à cocher en fonction de la sélection
    for I := 0 to CheckListBox.Items.Count - 1 do
    begin
      CheckboxStates[I] := CheckListBox.Checked[I];
    end;
  end;
  Result := True;
end;




procedure AboutButtonOnClick(Sender: TObject);
begin
  MsgBox('Vous êtes dans l''installateur des jeux de COCO !', mbInformation, mb_Ok);
end;

procedure URLLabelOnClick(Sender: TObject);
var
  ErrorCode: Integer;
begin
  ShellExecAsOriginalUser('open', '{#MyAppURL}', '', '', SW_SHOWNORMAL, ewNoWait, ErrorCode);
end;







procedure CreateAboutButtonAndURLLabel(ParentForm: TSetupForm; CancelButton: TNewButton);
var
  AboutButton: TNewButton;
  URLLabel: TNewStaticText;
begin
  AboutButton := TNewButton.Create(ParentForm);
  AboutButton.Left := ParentForm.ClientWidth - CancelButton.Left - CancelButton.Width;
  AboutButton.Top := CancelButton.Top;
  AboutButton.Width := CancelButton.Width;
  AboutButton.Height := CancelButton.Height;
  AboutButton.Anchors := [akLeft, akBottom];
  AboutButton.Caption := '&About...';
  AboutButton.OnClick := @AboutButtonOnClick;
  AboutButton.Parent := ParentForm;

  URLLabel := TNewStaticText.Create(ParentForm);
  URLLabel.Caption := 'www.Projet-Corentin-k.com';
  URLLabel.Cursor := crHand;
  URLLabel.OnClick := @URLLabelOnClick;
  URLLabel.Parent := ParentForm;
  { Alter Font *after* setting Parent so the correct defaults are inherited first }
  URLLabel.Font.Style := URLLabel.Font.Style + [fsUnderline];
  URLLabel.Font.Color := clHotLight
  URLLabel.Top := AboutButton.Top + AboutButton.Height - URLLabel.Height - 2;
  URLLabel.Left := AboutButton.Left + AboutButton.Width + ScaleX(20);
  URLLabel.Anchors := [akLeft, akBottom];
end;

 function GetSystemMetrics(nIndex: Integer): Integer;
  external 'GetSystemMetrics@user32.dll stdcall';

procedure InitializeWizard();
var
  ScreenWidth: Integer;
  ScreenHeight: Integer;
  WindowWidth: Integer;
  WindowHeight: Integer;
begin
   ScreenWidth := GetSystemMetrics(0); // Largeur de l'écran
  ScreenHeight := GetSystemMetrics(1); // Hauteur de l'écran
   WindowWidth := Round(ScreenWidth *0.6);
  WindowHeight := Round(ScreenHeight*0.6 );
  { Custom wizard pages }
  WizardForm.Height := WindowWidth;              //****Hauteur
  WizardForm.Width := WindowHeight;               //****Largeur
  WizardForm.Color := clSilver; 
  CreateTheWizardPages;

  
   
     
  WizardForm.OuterNotebook.Top := Round(WindowHeight * 0.01);;    //**** [ Cadre du bloc principal ]
  WizardForm.OuterNotebook.Left := Round(WindowWidth * 0.02);;  
  WizardForm.OuterNotebook.Height := Round(WindowHeight * 0.7);;
  WizardForm.OuterNotebook.Width := Round(WindowWidth * 0.5);;
     
  WizardForm.MainPanel.Color :=  clSilver;
//**************** Zone Bloc principal **************
 
  WizardForm.InnerPage.Color :=  clSilver;  //****Couleur de fond du bloc principal
  
 {clBlack, clMaroon, clGreen, clOlive, clNavy, clPurple, clTeal, clGray, clSilver, 
 clRed, clLime, clYellow, clBlue, clFuchsia, clAqua, clWhite. }
 
  
 //**************** Zone Menu supérieur ************** 
 
  
 
  WizardForm.PageNameLabel.Top := Round(WindowHeight * 0.02); 
  WizardForm.PageNameLabel.Left := Round(WindowWidth * 0.02); 
  WizardForm.PageNameLabel.Font.Size := 15; 
  WizardForm.PageNameLabel.Font.Name := 'Comic Sans MS';
  WizardForm.PageNameLabel.AutoSize := True;
  WizardForm.PageNameLabel.Color :=  clSilver;
  WizardForm.PageDescriptionLabel.Top := Round(WindowHeight * 0.1); // 11% à partir du haut
  WizardForm.PageDescriptionLabel.Width := Round(WindowWidth * 0.5); // 50% de la largeur
  WizardForm.PageDescriptionLabel.Color :=  clSilver;

  SetArrayLength(CheckboxStates, CheckListBox.Items.Count);
  { Custom controls }

  CreateAboutButtonAndURLLabel(WizardForm, WizardForm.CancelButton);

  { Custom beveled label }

  WizardForm.BeveledLabel.Caption := ' Autre ';
end;






{ Création du tableau de boolean pour savoir si les cases ont été Check }
function MyProgCheck(nombre:integer): Boolean;
begin
  
  if CheckboxStates[nombre] then
  begin
      Result :=True;
      
  end
  else 
  begin
  Result := False;
  end;
end;




procedure InitializeUninstallProgressForm();
begin
    
  { Custom controls }

  CreateAboutButtonAndURLLabel(UninstallProgressForm, UninstallProgressForm.CancelButton);
end;









