
Write-Host "Executing Script 2 "
..\Debug\TextSearchCompCSharpClient.exe -Path ".." /R  /O  -Files "*.cpp" "*.h" "*.c" -Words "<iostream>" "#include" "<vector>" "std::cout"  > .\TextSearchCompCSharpClient_Result2.txt


Write-Host "Press any key to continue ..."
Write-Host "Output is in the Root Project Directory Under Similar Name ==>  TextSearchCompCSharpClient_Result* ..."

$x = $host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")

