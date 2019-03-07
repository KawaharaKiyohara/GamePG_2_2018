@echo on

@rem ゲームプログラミングⅡ　セットアップバッチ

@setlocal


@set CURRENT_DIR=%~dp0

@pushd %CURRENT_DIR%

@cd "..\Sample"

@for /d %%a in (.\*) do (
	
@rem シンボリックリンクの作成
	
@rem まずは削除から
	
pushd %%a
	
	
rmdir /s /q tkEngine
	
del /F tkEngine
	
	
@rem 続いて作成。
	
mklink /D "tkEngine" "..\..\tkEngine"
	
@popd
)


@popd
