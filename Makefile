LATEXCMD = xelatex -shell-escape
export max_print_line = 1048576

.PHONY: help
help:
	@echo "This makefile builds NACTL (NJU ACM Contest Template Library)"
	@echo "which is modified from KACTL (KTH ACM Contest Template Library)"
	@echo ""
	@echo "Available commands are:"
	@echo "	make fast	- to build the KACTL, quickly (only runs LaTeX once)"
	@echo "	make nactl	- to build the KACTL"
	@echo "	make clean	- to clean up the build process"
	@echo "	make veryclean	- to clean up and remove nactl.pdf"
	@echo "	make help	- to show this information"
	@echo ""
	@echo "For more information see the file 'doc/README'"

.PHONY: fast
fast:
	cd build && $(LATEXCMD) nactl.tex < /dev/null
	cp build/nactl.pdf nactl.pdf

.PHONY: nactl
nactl: test-session.pdf
	cd build && $(LATEXCMD) nactl.tex && $(LATEXCMD) nactl.tex
	cp build/nactl.pdf nactl.pdf

.PHONY: clean
clean: 
	cd build && rm -f nactl.aux nactl.log nactl.tmp nactl.toc nactl.pdf nactl.ptc

.PHONY: veryclean
veryclean: clean
	rm -f nactl.pdf test-session.pdf

test-session.pdf: content/test-session/chapter.tex
	cd build && $(LATEXCMD) test-session.tex
	cp build/test-session.pdf test-session.pdf
