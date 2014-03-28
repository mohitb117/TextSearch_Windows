

Write-Host "Executing Script 4 "
..\Debug\TextSearchCompCSharpClient.exe -Path ".." /R  -Files "*.*" -Words "<iostream>" "#include" "<vector>" "std::cout" > .\TextSearchCompCSharpClient_Result4.txt


Write-Host "Press any key to continue ..."
Write-Host "Output is in the Root Project Directory Under Similar Name ==>  TextSearchCompCSharpClient_Result* ..."

$x = $host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")

