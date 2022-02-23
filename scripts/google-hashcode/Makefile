.PHONY: run

run: compile generate_output score_submission

compile:
	g++ solution.cpp -o a.out
	g++ score.cpp -o score.out

generate_output:
	./generate_output.sh

score_submission:
	./score_submission.sh

