# Stop on first error
$ErrorActionPreference = "Stop"

Write-Host "Cleaning build directory..." -ForegroundColor Yellow
platformio run --target clean

Write-Host "Removing .pio build folder..." -ForegroundColor Yellow
Remove-Item -Path ".pio" -Recurse -Force -ErrorAction SilentlyContinue

Write-Host "Starting fresh build..." -ForegroundColor Yellow
platformio run

Write-Host "Build process completed" -ForegroundColor Green
