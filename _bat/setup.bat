@echo on

@rem �Q�[���v���O���~���O�U�@�Z�b�g�A�b�v�o�b�`

@setlocal


@set CURRENT_DIR=%~dp0

@pushd %CURRENT_DIR%

@cd "..\Sample"

@for /d %%a in (.\*) do (
	
@rem �V���{���b�N�����N�̍쐬
	
@rem �܂��͍폜����
	
pushd %%a
	
	
rmdir /s /q tkEngine
	
del /F tkEngine
	
	
@rem �����č쐬�B
	
mklink /D "tkEngine" "..\..\tkEngine"
	
@popd
)


@popd
