

Write-Host "Executing Script 3 "
..\Debug\TextSearchCompCSharpClient.exe -Path ".."  /O  -Files "*.*" -Words "<iostream>" "#include" "<vector>" "std::cout" > .\TextSearchCompCSharpClient_Result3.txt


Write-Host "Press any key to continue ..."
Write-Host "Output is in the Root Project Directory Under Similar Name ==>  TextSearchCompCSharpClient_Result* ..."

$x = $host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")

