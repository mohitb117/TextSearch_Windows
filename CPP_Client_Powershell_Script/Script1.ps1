
Write-Host "Executing Script 1"
..\Debug\CPLUSPLUSCLIENT.exe -Path ".." -Files "*.*" -Words "<iostream>" "#include" "<vector>" "std::cout" > .\CPPClientOutput_Result1.txt
Write-Host "Please Wait for a few seconds , then press any key ..."
cmd /c pause | out-null
Write-Host "Press any key to continue ..."
Write-Host "Output is in the Root Project Directory Under Similar Name ==>  CPPClientOutput_Result* ..."

$x = $host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")
