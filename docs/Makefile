default: 
	if not exist "build" mkdir "build
	pandoc "specification.md" "plan.md" "skeleton.md" --template "docs_template.tex" -o "build/dokumentacio.pdf" --variable neptun=$(NEPTUN)

clean:
	rmdir /S /Q "build"