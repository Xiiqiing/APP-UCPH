#ifndef SUBMISSION_FILENOTOPENEXCEPTION_HPP_
#define SUBMISSION_FILENOTOPENEXCEPTION_HPP_

#include "Exception.hpp"

class FileNotOpenException : public Exception {
	public:
		FileNotOpenException(std::string prob);
		void ReadFile1(const std::string &filename, double x[], double y[]);
};

#endif /* SUBMISSION_FILENOTOPENEXCEPTION_HPP_ */
