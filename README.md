<div id="top"></div>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/sYCH3L/PATS">
    <img src="images/logo.jpg" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">Pretty Awesome Testing System</h3>

  <p align="center">
    Modular testing system for behavioral testing of an embedded device, suited running on rpi/alternatives with electrical connections on DUT
    <br />
    <a href="https://github.com/sYCH3L/PATS"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/sYCH3L/PATS">View Demo</a>
    ·
    <a href="https://github.com/sYCH3L/PATS/issues">Report Bug</a>
    ·
    <a href="https://github.com/sYCH3L/PATS/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

Modular Testing system for embedded systems with REST API interaction

<p align="right">(<a href="#top">back to top</a>)</p>



### Built With

* [Boost.log](https://www.boost.org/doc/libs/1_71_0/libs/log/doc/html/index.html)
* [Pistace REST API](https://pistache.io/)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.
* apt
  ```sh
  sudo apt install libboost-log1.71-dev libboost-program-options1.71-dev
  ```
* Pistache
    [Documentation](  https://pistache.io/docs/)_

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/sYCH3L/PATS.git
   ```
2. Build PATS
   ```sh
   mkdir build && cd build && cmake .. && make
   ```
3. Run ATS
   ```sh
   ./ATS
   ```

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [] Write module compiling instructions
- [] Write example front-end for controlling
- [] Running testplans api call needs finishing
- [] TestEngine
    - [] Test the current functionality

See the [open issues](https://github.com/sYCH3L/PATS/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

sYCH3L - enari.saar@gmail.com

Project Link: [https://github.com/sYCH3L/PATS](https://github.com/sYCH3L/PATS)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* []()
* []()
* []()

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/sYCH3L/PATS.svg?style=for-the-badge
[contributors-url]: https://github.com/sYCH3L/PATS/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/sYCH3L/PATS.svg?style=for-the-badge
[forks-url]: https://github.com/sYCH3L/PATS/network/members
[stars-shield]: https://img.shields.io/github/stars/sYCH3L/PATS.svg?style=for-the-badge
[stars-url]: https://github.com/sYCH3L/PATS/stargazers
[issues-shield]: https://img.shields.io/github/issues/sYCH3L/PATS.svg?style=for-the-badge
[issues-url]: https://github.com/sYCH3L/PATS/issues
[license-shield]: https://img.shields.io/github/license/sYCH3L/PATS.svg?style=for-the-badge
[license-url]: https://github.com/sYCH3L/PATS/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/enarisaar/
[product-screenshot]: images/screenshot.png