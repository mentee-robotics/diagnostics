#ifndef DIAGNOSTIC_UPDATER__BASE_CLASSES_HPP_
#define DIAGNOSTIC_UPDATER__BASE_CLASSES_HPP_

#include "diagnostic_updater/diagnostic_updater.hpp"

namespace diagnostic_updater {

class DiagnosticProducer {
   public:
    DiagnosticProducer(std::string task_name)
        : produce_diagnostics_func(task_name, std::bind(&DiagnosticProducer::produce_diagnostics,
                                                        this, std::placeholders::_1)) {}

    FunctionDiagnosticTask produce_diagnostics_func;

   private:
    virtual void produce_diagnostics(DiagnosticStatusWrapper& stat) = 0;
};
}  // namespace diagnostic_updater

#endif  // DIAGNOSTIC_UPDATER__BASE_CLASSES_HPP_