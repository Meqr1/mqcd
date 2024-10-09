# What is mqcd?
- mqcd is a tool for windows powershell and microsoft terminal users which helps sync the starting directory for any new opened powershell window.

# How to use it?  
if you already have created a powershell config insert these lines in it...


```pwsh
Remove-Alias cd

if (Test-Path $historyPath) {
    ~/mqcd.exe get | sl
}

function cd ($path) {
    if ($path) {

        sl $path

        # Check if 'sl' succeeded
        if (-not $?) {
            Write-Host "Error: Failed to change directory to $path."
            return  # Exit the function if 'sl' fails
        }

        $path = Get-Location

        ~/mqcd.exe set $path
    } else {
        sl

        # Check if 'sl' succeeded
        if (-not $?) {
            Write-Host "Error: Failed to change to the home directory."
            return  # Exit the function if 'sl' fails
        }

        ~/mqcd.exe set ~
    }
}
```

this code snippet will remove the alias cd and add a custom cd function

- if you dont have a custom powershell config read this https://lazyadmin.nl/powershell/powershell-profile/

# !IMPORTANT

put the mqcd.exe on the ~/mqcd.exe path
