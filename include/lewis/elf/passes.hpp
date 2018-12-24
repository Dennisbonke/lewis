
#pragma once

#include <memory>
#include <lewis/elf/object.hpp>

namespace lewis::elf {

struct ObjectPass {
    virtual ~ObjectPass() = default;

    virtual void run() = 0;
};

// The following passes are implemented using Pimpl.

// Creates header fragments required for the desired file type.
struct CreateHeadersPass : ObjectPass {
    static std::unique_ptr<CreateHeadersPass> create(Object *elf);
};

// Layouts fragments in the file and in virtual memory.
struct LayoutPass : ObjectPass {
    static std::unique_ptr<LayoutPass> create(Object *elf);
};

} // namespace lewis::elf
