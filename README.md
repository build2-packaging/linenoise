# build2 Package for `linenoise`

[`linenoise`](https://github.com/antirez/linenoise) is A minimal, zero-config, BSD licensed, readline replacement used in Redis, MongoDB, Android and many other projects.

[![Official](https://img.shields.io/website/https/github.com/antirez/linenoise.svg?down_message=offline&label=Official&style=for-the-badge&up_color=blue&up_message=online)](https://github.com/antirez/linenoise)
[![build2](https://img.shields.io/website/https/github.com/build2-packaging/linenoise.svg?down_message=offline&label=build2&style=for-the-badge&up_color=blue&up_message=online)](https://github.com/build2-packaging/linenoise)
[![cppget.org](https://img.shields.io/website/https/cppget.org/liblinenoise.svg?down_message=offline&label=cppget.org&style=for-the-badge&up_color=blue&up_message=online)](https://cppget.org/liblinenoise)
[![queue.cppget.org](https://img.shields.io/website/https/queue.cppget.org/liblinenoise.svg?down_message=empty&down_color=blue&label=queue.cppget.org&style=for-the-badge&up_color=orange&up_message=running)](https://queue.cppget.org/liblinenoise)

## Usage

First, add the alpha section of the `cppget.org` repository to your project's `repositories.manifest` to be able to fetch this package.

```
:
role: prerequisite
location: https://pkg.cppget.org/1/alpha
# trust: ...
```

If the stable section of `cppget.org` is not an option then add this Git repository itself instead as a prerequisite.

```
:
role: prerequisite
location: https://github.com/build2-packaging/linenoise.git
```

Add the respective dependency in your project's `manifest` file to make the package available for import.

```
depends: liblinenoise ^1.0.1-
```

The library can then be imported by the following declaration in a `buildfile`.

```
import linenoise = liblinenoise%lib{linenoise}
```

## Configuration

There are no configuration options available.

## Issues and Notes

- Windows is not support by `linenoise`.
- At the point of writing, the upstream `linenoise` repository only provides the single release tag `1.0` that is older than eight years. To also get access to the newest changes without introducing name clashes with a possible second release, version `1.0.1-a.1` is used for the package.

## Contributing

Thanks in advance for your help and contribution to keep this package up-to-date.
For now, please, file an issue on [GitHub](https://github.com/build2-packaging/linenoise/issues) for everything that is not described below.

### Recommend Updating Version

Please, file an issue on [GitHub](https://github.com/build2-packaging/linenoise/issues) with the new recommended version.

### Update Version by Pull Request

1. Fork the repository on [GitHub](https://github.com/build2-packaging/linenoise) and clone it to your local machine.
2. Run `git submodule init` and `git submodule update` to get the current upstream directory.
3. Inside the `upstream` directory, checkout the new library version `X.Y.Z` by calling `git checkout vX.Y.Z` that you want to be packaged.
4. If needed, change source files, `buildfiles`, and symbolic links accordingly to create a working build2 package. Make sure not to directly depend on the upstream directory inside the build system but use symbolic links instead.
5. Update library version in `manifest` file if it has changed or add package update by using `+n` for the `n`-th update.
6. Make an appropriate commit message by using imperative mood and a capital letter at the start and push the new commit to the `master` branch.
7. Run `bdep ci` and test for errors.
8. If everything works fine, make a pull request on GitHub and write down the `bdep ci` link to your CI tests.
9. After a successful pull request, we will run the appropriate commands to publish a new package version.

### Update Version Directly if You Have Permissions

1. Inside the `upstream` directory, checkout the new library version `X.Y.Z` by calling `git checkout vX.Y.Z` that you want to be packaged.
2. If needed, change source files, `buildfiles`, and symbolic links accordingly to create a working build2 package. Make sure not to directly depend on the upstream directory inside the build system but use symbolic links instead.
3. Update library version in `manifest` file if it has changed or add package update by using `+n` for the `n`-th update.
4. Make an appropriate commit message by using imperative mood and a capital letter at the start and push the new commit to the `master` branch.
5. Run `bdep ci` and test for errors and warnings.
6. When successful, run `bdep release --tag --push` to push new tag version to repository.
7. Run `bdep publish` to publish the package to [cppget.org](https://cppget.org).
