

Write-Host "Executing Script 1 "
..\Debug\TextSearchCompCSharpClient.exe -Path ".." -Files "*.*" -Words "<iostream>" "#include" "<vector>" "std::cout" > .\TextSearchCompCSharpClient_Result1.txt


Write-Host "Press any key to continue ..."

Write-Host "Output is in the Root Project Directory Under Similar Name ==>  TextSearchCompCSharpClient_Result* ..."

$x = $host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")

