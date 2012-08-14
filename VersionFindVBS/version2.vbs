strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
& "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")

'Set objWMIService = GetObject("winmgmts:\\" & strComputer & "\root\cimv2")


Set colFiles = objWMIService. _
ExecQuery("Select * from CIM_DataFile where Extension = 'exe'")

For Each objFile in colFiles
  If objFile.Version = "1,0,0,1" Then
    strCopy = "C:\version_find\" & objFile.FileName _
    & "." & objFile.Extension
    objFile.Copy(strCopy)
    objFile.Delete
  End If
Next
msgbox("Complete")