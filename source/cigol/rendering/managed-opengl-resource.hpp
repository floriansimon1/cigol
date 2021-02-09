#pragma once

#include <cigol/base/non-copyable.hpp>

#include <glad/glad.h>

#include <optional>
#include <functional>

namespace cigol::rendering {
    class ManagedOpenglBuffer: private cigol::base::NonCopyable {
        public:
            using Deleter = std::function<void(GLsizei number, const GLuint* buffers)>;

            ManagedOpenglBuffer(
                const Deleter&  deleter,
                const GLuint    descriptor
            );

            ManagedOpenglBuffer(
                ManagedOpenglBuffer&& buffer
            );

            ~ManagedOpenglBuffer();

            static ManagedOpenglBuffer
            createVertexArray();

            static ManagedOpenglBuffer
            createGenericBuffer();

            GLuint unwrap() const;

        private:
            std::optional<GLuint> descriptor;
            Deleter               deleter;
    };
}
